# Exploring-ArduinoJson
Simple tests to explore the limits of the library and understand its intended useage.

Key points taken,
  - No pointers, objects must be used to create new structs and/or classes to pass to other compoents of
  the program.
  - Re-uses input memory if input memory is as read-write. Using const char* causes a copy to occur, increasing
  memory consumption.
  - In general, using JSON is adding complexity but easeing configuration and interoperability. I see a benifit.
  
More Investigation needed,
  - Using Stream may be useful to inspect, extract and queue sub messages/string for other RTOS tasks to deserialise themselves.
  - Is converting JSON striaght to struct and/or classes more efficient than holding multiple task JSON documents?
  
Yell out with any thoughts.

See library at,
https://arduinojson.org/
