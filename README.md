# Float Detecting Deterministic Finite State Automaton

DFA Class in C++ that processes a string character stream to accept/reject based on whether they represent floats in the IEEE 754 standard.

## Implementation
DFA object initialized as a 2D array with state on the x-axis, redirection choice on the y-axis and next state as the value. With each character input, the current state is updated by querying the 2D array for the next state with a final check at end of stream to determine if the last state is accepting or rejecting.
