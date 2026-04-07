Memory decisions - Mini Project 8

I used unique_ptr for each node because RoutingEngine is the only thing that should own them. They get made in the constructor and die when the engine does, so unique_ptr handles delete for you and you dont get double free bugs

Edges are just int and double so I kept them in vector Edge by value. Nothing shares an edge record, and its not worth pointer chasing for something that small.

visited is a local vector inside findPath. Each search needs its own visited flags and the graph is only 6 nodes so it's not worth it to store it on the class. It gets cleaned up when the function returns.

shared_ptr would make sense if two different parts of the program both needed to keep the same node alive. Here its only RoutingEngine so unique_ptr is enough.

If you used raw new and forgot delete you leak. Also double delete or use after free errors. Smart pointers mostly avoid that because the destructor runs when the owner goes out of scope.
