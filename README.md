<p align="center">
    <img src="push_swapm.png" alt="Badge Name">
</p>

## Overview
The `push_swap` project is an algorithmic challenge aimed at sorting data on stacks with a limited set of operations, optimizing for the smallest number of actions.
This implementation achieves a 125% score by employing a chunk-based sorting algorithm and efficient data management using linked lists.

## Methodology
- **Data Structure**: Utilized linked lists for stack management, ensuring dynamic and efficient data handling.
- **Sorting Algorithm**: Adopted a chunk-based sorting strategy. This approach divides the data into manageable 'chunks' to optimize sorting operations, significantly reducing the number of moves required for large data sets.

## Challenges and Solutions
- **Efficiency Optimization**: The primary challenge was to minimize the number of operations. By experimenting with different chunk sizes and tweaking the algorithm, an optimal balance was achieved.
- **Large Data Sets**: Handling large numbers effectively was crucial. The chunk-based approach proved effective, consistently sorting large datasets with minimal moves.

## Bonus Achievements
- **Visualizer**: Developed a visualizer to demonstrate the sorting process in real-time, providing valuable insights into the algorithm's performance and aiding in further optimization.
- **Error Handling**: Implemented comprehensive error handling to manage incorrect inputs and unexpected scenarios gracefully.

## Usage
To compile the `push_swap` and `checker` programs, run:
``` bash
make
make bonus
./push_swap [numbers_to_sort]
./checker [numbers_to_sort]
```



## Test Results
- **Efficiency**: Achieved an average of less than 5500 moves on sets of 500 numbers.
- **Scalability**: Demonstrated consistent efficiency even with small datasets, surpassing the baseline requirements.

## Reflections
This project was a valuable exercise in algorithm optimization and data structure choice. The chunk-based approach not only improved efficiency but also offered insights into handling complex data sorting with constrained operations.
Future improvements could include further algorithmic refinements and exploring alternative data structures for even more efficiency.
