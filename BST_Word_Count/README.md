Word Counter

functions:
-Can read words from a text file and track how many times each word repeats
-Ability to add words to the count or remove them entirely from the list
-Display entire list or save it to a file

Use:
1. Download the BST_word_count folder
2. Open terminal and maneuver to folder
3. run 'make' command to compile program
4. run './WordCount' to run program
5. enter on-screen commands to use program


Description
This Word counter makes use of a BST to try and streamline the process of word counting and organization.  You can use it to read any text at a decent speed and save the list to a file for later use.

Known Problems:
It does run int segmentation faults sometimes. The easily repeatable ones are when trying to display the list when it hasnt been populated yet and when removing the last member of the list (display wise).

Another notable problem is sometimes children elements get deleted along with the desired deleted element (spent awhile trying to go through deleteNode again but can't figure out the cause)