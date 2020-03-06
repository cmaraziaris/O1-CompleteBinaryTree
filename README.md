# Complete Binary Tree

### A Generic Complete Binary Tree implementation , with O(1) [Amortized Complexity](https://en.wikipedia.org/wiki/Amortized_analysis) in :
> - #### Insertion
> - #### Removal of last node
> - #### Getting the last node

## Usage
### Run with Default Arguments
```c
$ cd ~/O1-CompleteBT/CBT_Impl
```
#### Set Strings as tree items (Default):
```c
$ make run
```
or 
```c
$ make run ITEM_TYPE=str
```
#### Set Integers as tree items:
```c
$ make run ITEM_TYPE=int
```
### Run with Custom Arguments

```c
$ cd ~/O1-CompleteBT/CBT_Impl

$ make 

$ ./O1_cbt  <size_of_tree>  <minimum_num_of_elements>  <maximum_num_of_elements>
```

**Note :**  *Running with default arguments, will create and print a Complete Binary Tree with 22 nodes.       
 (size_of_tree = 22).   
                                                                             
Then, there will be 100.000 , 1.000.000 and 10.000.000 insertions and removals in order to demonstrate O(1) Amortized Complexity.                                                                              

(minimum_num_of_elements = 100.000 , maximum_num_of_elements = 10.000.000)*

                                                                                      

### Clean

```c
$ make clean
```

### Check for memory leaks (Requires [Valgrind](https://valgrind.org/) installation)

```c
$ make check
```
