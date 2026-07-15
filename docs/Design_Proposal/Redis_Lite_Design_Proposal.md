
# Design Proposal: Redis Lite

## Section 1 – Public API and Architecture

The **Redis Lite** application is a lightweight, single-threaded, command-line key-value database built strictly on top of a custom **HashMap** implementation. Operating entirely as an in-memory data store, all records exist dynamically within volatile memory (RAM) during application runtime and are systematically cleared when the program terminates.

Data is mapped using uniform **key-value pairs**, where both keys and values are processed as standard strings. The application exposes an interactive **REPL (Read-Eval-Print Loop)** command-line interface that allows developers to run atomic operations such as database insertion, state tracking, deletion, data updates, and total purges.

### Public Interface

The public surface area of the application is intentionally kept minimal and encapsulated, exposing only the initializer and the execution entry point:

| Method | Return Type | Functional Description |
|:---|:---|:---|
| `RedisCLI()` | Constructor | Initializes the primary storage map container, zeroes the telemetry metrics, and prepares the internal execution state. |
| `run()` | `void` | Launches the interactive REPL execution loop, processing incoming user commands from standard input until an explicit `EXIT` sequence is initiated. |

### Supported Console Commands

The engine translates terminal textual streams into distinct actions mapped out below:

| Command | Syntax | Operational Behavior | Success Output |
|:---|:---|:---|:---|
| **SET** | `SET <key> <value>` | Inserts a new key-value string pair into the data store or updates the value if the key is already present. | `OK` |
| **GET** | `GET <key>` | Queries the system and retrieves the corresponding string value linked to the target key. | Spits out value string, or `(nil)` if missing |
| **DEL** | `DEL <key>` | Removes the specified key-value pair completely from the active data structure. | `1` (removed) or `0` (not found) |
| **EXISTS**| `EXISTS <key>` | Verifies containment of a key without retrieving its associated value payloads. | `1` (exists) or `0` (does not exist) |
| **COUNT** | `COUNT` | Evaluates and prints the aggregate number of key-value records currently managed inside RAM. | Integer size |
| **CLEAR** | `CLEAR` | Evaporates all data elements from the backing collection, returning the system to a clean initialization state. | `OK` |
| **KEYS** | `KEYS` | Discovers and enumerates all primary keys saved in the system, outputting them for global indexing. | Space-separated list of keys |
| **HELP** | `HELP` | Prints a diagnostic dashboard displaying syntax definitions and usage instructions for all valid options. | Text guide block |
| **EXIT** | `EXIT` | Safely signals the execution loop to wind down, breaking out of the REPL and concluding the process lifecycle. | Program ends |

---

## Section 2 – Internal Representation & Pipeline

Architecturally, Redis Lite functions as an isolated abstraction layer wrapped around the project’s custom **HashMap**. All heavy lifting concerning data allocation, key hashing, collision chains, and index lookups is handled by the underlying map. The `RedisCLI` class focuses entirely on stream tokenization, argument checking, routing, and formatting console outputs.

```cpp
class RedisCLI
{
private:

    HashMap<std::string, std::string> store;

    bool running;

    void displayPrompt() const;

    DynamicArray<std::string> parseCommand(const std::string& input) const;

    void executeCommand(const DynamicArray<std::string>& tokens);

    void handleSet(const DynamicArray<std::string>& tokens);

    void handleGet(const DynamicArray<std::string>& tokens);

    void handleDel(const DynamicArray<std::string>& tokens);

    void handleExists(const DynamicArray<std::string>& tokens);

    void handleCount();

    void handleClear();

    void handleKeys();

    void handleHelp();

public:

    RedisCLI();

    void run();
};
```

## Internal Data Members

```cpp
HashMap<std::string,std::string> store;

bool running;
```

- **store** stores all key-value pairs using the HashMap implementation.
- **running** controls the execution of the command loop.
---

## Memory Layout

Each bucket points to the head of a singly linked list.

<img width="1536" height="1024" alt="image" src="https://github.com/SuperCodersOrg/DS_LIBRARY-VIVEK-Batch2/blob/main/docs/Design_Proposal/MemoryDiagrams/redislite.png?raw=true" />


---
## Command Processing

The application continuously accepts commands from the user until the `EXIT` command is entered.

```
User Input
      │
      ▼
parseCommand()
      │
      ▼
executeCommand()
      │
      ▼
Command Handler
      │
      ▼
HashMap Operation
      │
      ▼
Output
```

User input is read using **std::getline()** and divided into tokens using whitespace as delimiters. The first token is converted to uppercase so commands are processed in a case-insensitive manner. Empty input lines are ignored.

## Memory Management

Redis Lite does not allocate dynamic memory directly. All memory management is handled by the underlying HashMap implementation.

When the RedisCLI object is destroyed, the HashMap destructor automatically releases all allocated memory. Since RedisCLI owns no raw pointers, the compiler-generated destructor, copy constructor, and assignment operator are sufficient.

---

# Section 3 – Complexity Estimates

<!-- | Operation | Best Case | Average Case | Worst Case | Explanation |
|-----------|:---------:|:------------:|:----------:|-------------|
| `SET` | **O(1)** | **O(1)** | **O(n)** | Calls `HashMap::put()`. Worst case occurs when all keys collide into one bucket. |
| `GET` | **O(1)** | **O(1)** | **O(n)** | Uses `contains()` and `get()` to locate the key. |
| `DEL` | **O(1)** | **O(1)** | **O(n)** | Calls `HashMap::remove()`. Worst case traverses an entire collision chain. |
| `EXISTS` | **O(1)** | **O(1)** | **O(n)** | Uses `HashMap::contains()`. |
| `COUNT` | **O(1)** | **O(1)** | **O(1)** | Returns the maintained element count. |
| `CLEAR` | **O(n)** | **O(n)** | **O(n)** | Removes every stored key-value pair. |
| `KEYS` | **O(n)** | **O(n)** | **O(n)** | Traverses every bucket and node to display keys. |
| `HELP` | **O(1)** | **O(1)** | **O(1)** | Prints a predefined help message. |
| `EXIT` | **O(1)** | **O(1)** | **O(1)** | Stops the command loop. | -->

## Section 3 – Complexity Estimates

| Operation | Best Case | Average Case | Worst Case | Operational Explanation |
|-----------|:---------:|:------------:|:----------:|-------------------------|
| **`SET`** | **O(1)** | **O(1)** | **O(n)** | Calls `HashMap::put()`. The average case achieves constant-time indexing. The worst case occurs when every key hashes to the same bucket, creating a single collision chain. |
| **`GET`** | **O(1)** | **O(1)** | **O(n)** | Uses `contains()` and `get()` methods to retrieve the value associated with a key. Constant-time lookup is achieved on average through efficient hashing. |
| **`DEL`** | **O(1)** | **O(1)** | **O(n)** | Invokes `HashMap::remove()`. The worst case occurs when the target key is located at the end of a long collision chain. |
| **`EXISTS`** | **O(1)** | **O(1)** | **O(n)** | Delegates directly to `HashMap::contains()` to determine whether a key exists. |
| **`COUNT`** | **O(1)** | **O(1)** | **O(1)** | Returns the internally maintained count of stored key-value pairs. |
| **`CLEAR`** | **O(n)** | **O(n)** | **O(n)** | Traverses all stored entries, releasing allocated memory and clearing the hash table. |
| **`KEYS`** | **O(n)** | **O(n)** | **O(n)** | Iterates through every bucket and collision chain to collect and display all stored keys. |
| **`HELP`** | **O(1)** | **O(1)** | **O(1)** | Prints a predefined help menu containing all supported commands. |
| **`EXIT`** | **O(1)** | **O(1)** | **O(1)** | Sets the `running` flag to `false`, immediately terminating the command-processing loop. |
---

# Section 4 – Design Decisions

## Decision 1 – HashMap as Backing Store

**Chosen:** HashMap

**Reason**

HashMap provides average-case **O(1)** insertion, lookup, update, and deletion. Since Redis Lite is fundamentally a key-value database, HashMap is the most suitable underlying data structure.

**Rejected:** DynamicArray or LinkedList

**Reason**

Both require linear search (**O(n)**) for lookup and deletion, making them inefficient for key-value storage.

---

## Decision 2 – String Keys and Values

**Chosen:** `std::string`

**Reason**

All user input is received as text from the command line. Using strings for both keys and values keeps parsing simple and avoids unnecessary type conversion.

**Rejected:** Multiple value types

**Reason**

Supporting different data types would require additional parsing, serialization, and type management, increasing implementation complexity beyond the project scope.

---

## Decision 3 – Case-Insensitive Commands

**Chosen:** Convert commands to uppercase before execution.

**Reason**

This allows users to enter commands such as `SET`, `set`, or `Set` without affecting functionality, improving usability.

The first token is converted to uppercase so commands are processed in a case-insensitive manner.

**Rejected:** Case-sensitive commands

**Reason**

Requiring exact capitalization provides no practical advantage and reduces user convenience.

---
