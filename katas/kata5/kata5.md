Kata 5: Infografic
You want to build a word cloud, an infographic where the size of a word corresponds to how often it appears in the body of text.

To do this, you'll need data. Write code that takes a long string and builds its word cloud data in a hash table ↴ , where the keys are words and the values are the number of times the words occurred.

Think about capitalized words. For example, look at these sentences:

  "After beating the eggs, Dana read the next step:"

"Add milk and eggs, then add flour and sugar."

What do we want to do with "After", "Dana", and "add"? In this example, your final hash table should include one "Add" or "add" with a value of  2


The first we have to do is being able to read the words from a .txt file

Once we are able to do so we need to save them into a hash table, or so called hash them.

  The collitions of the hash table will increase a counter for that element on 1
    see attached picture for a sketch of the hash table structure


Ways to do the hash
  By alphabet
  First In, first treathed 
  Make a hash key with the ascii code of the word addint the value of each character
    For this we need to know the size that the hash will have and make a module operation to this value so we can introduce it to the hash
    In this case it will be needed that each element of the table point to an other data structure that will contain the string of the word and the counter of the times it has appeared.
    With this it should be possible to store any word we want and any quantity of words.