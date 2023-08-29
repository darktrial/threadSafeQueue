# threadSafeQueue
## thread safe queue header only library.

### To use
#### 1. Include tsq.hpp 
#### 2. thread safe queue API
#####    2.1 Create thread safe queue
   `threadSafeQueue<testobj> tsq;`
#####    2.2 push data
   `testobj t;`
   `tsq.push(t);`
#####    2.3 wait and pop data 
   `testobj t;`
   `tsq.wait_and_pop(t);`


Please refer to test.cpp for more references.
