# CS163 Projects – Data Structures

**myChat ADT**

- A simple chat ADT and testing application that simulates popular functions in chat applications.
- Utilizes a node chain to connect chat rooms and another node chain in each chat room for the messages

**Plane\_Boarding\_ADT**

- Utilizes a queue as a circular linked list to add and remove passengers from a &#39;preboard&#39; queue and then to a sorted &#39;board&#39; queue.
- Passengers from the sorted &#39;board&#39; queue are then &#39;pushed&#39; in sorted order into the plane &#39;stack&#39;, such that the person deepest into the plane boards first and then the lower rows. Passengers in each row also board in the order such that seats closer to the windows board first.
- The program is customizable to a plane of any &#39;halfrow&#39; size - i.e there needs to be an even number of seats in each row and only a single aisle.
- The plane &#39;stack&#39; is created as a linear linked list of arrays. Each node represents a row and its array the seats in that row.

**Event\_Management\_hasht\_ADT**

- Uses a hashtable to store events hashed by its keywords. Each event contains &#39;n&#39; keywords and therefore instanced &#39;n&#39; number of times in the hashtable. Instead of storing copies of events for the different keywords, a single event instance is pointed to by several pointers from possibly different hash indexes.
- LLL chain used as a collision resolution technique.
- O(1) performance on average for event retrieval and addition
- A sample data file &#39;events\_tej.txt&#39; included for performance benchmarking

#### **Event\_Management\_BST\_ADT**

- Essentially the same program as before, but this time using a binary search tree as the data structure.
- Search tree is maintained by event title rather than the keywords unlike before. This means that there aren&#39;t any duplicate events.
- The &#39;events\_tej.txt&#39; external data file with 73 titles is used here as well, and the height in accordance to these titles comes to 13. Therefore a relatively balanced performance can be expected with an average performance of O(log(2)(n)).
