# ESCALE

- A small lib for ("key", "value") cache.

## Usage

```cpp
#include <iostream>
#include "Cache.h"

int main() {
  Cache* cache = new Cache();

  cache->set("Key", "Value");
  std::cout << cache->get("Key") << std::endl;

  return 0;
}
```

Keep it simple, feel free to contribute. Have a nice day! :)
