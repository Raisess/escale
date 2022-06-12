# ESCALE

- A small lib for ("key", "value") cache.

## Usage

```cpp
#include <iostream>
#include "Cache.h"

int main() {
  Cache* cache = new Cache();

  cache->set("Key", "Value");
  std::cout << cache->get("Key") << std::endl; // Value

  return 0;
}
```

- Using a single instance

```cpp
#include <iostream>
#include "Cache.h"

int main() {
  Cache* cache_one = Cache::SingleInstance();

  cache_one->set("Key", "Value");
  std::cout << cache_one->get("Key") << std::endl; // Value

  Cache* cache_two = Cache::SingleInstance();

  std::cout << cache_two->get("Key") << std::endl; // Value

  return 0;
}
```

Keep it simple, feel free to contribute. Have a nice day! :)
