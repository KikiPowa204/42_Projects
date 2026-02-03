_This project has been created as part of the 42 curriculum by knajmech._

# Description

Push_Swap is a project that involves being given a list of numbers as an argument. Using two stacks, you have to sort the numbers in ascending order. The program prints out the instructions to the terminal, each one delimitted with a newline ('\n'). These are instructions for how one would be able to sort the numbers.

You can either use the provided linux checker, or use the beautiful one I made for my bonus (instructions below).

The program will print out the following instructions (with the parallel meaning).

- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

If the input is invalid (an input is not a number or there are duplicates of numbers) the program prints 'ERROR\n'.

# Instructions

1. Type make.
2. Run ./push_swap <put a string of numbers here>. Alternatively, you can also do ARG="<numbers>"; ./push_swap $ARG | ./checker $ARG

To use the bonus checker, try make bonus.

You can also run make fclean to get rid of the compiled programs and ofiles. You can also run make re to just run everything again.

# Resources

I used Gemini for the following problems:
* Come up with a sorting algorithm for recursion for the 7 numbers left in stack a.
* Help with chunking the numbers into two halves when first pushing everything to stack b.
* debugging my Makefile when creating the bonus.
* debugging my bonus checker when there were conflicting rules.

https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://github.com/alx-sch/push_swap

No code has been copied. All the resources simply explained turk algorithm.