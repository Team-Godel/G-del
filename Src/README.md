# Godel
A C++ library for Windows.

# To do:
- Make a method for link a graphic element with the window
- Change some variables with a vector of its type
- Re-factorize the code
- Try to use the OOP propeties for make a hierarchy that encapsulate all the library definitions (This is just a posibility, but it is not so necesary for now)
- For a better implementation of all the classes, instead of initialize the necesary values in the same class declaration, we can overcharge the constructors for each necesary case, i go to document this in the doc folder
- IMPORTANT: we need to make the lib really an interface, the user (the programmer) does not need to use (and will not use) NOTHING about winapi, really, the programmer should not know that the winAPI is here.
- ALSO IMPORTANT: Find a way for encapsulate all the window procedures, it is a feature sooo used in the winAPI implementation, and bassed in the last dot, we should make sure that the programmer will not to touch it.

# Notes
- I create here the doc folder because we need to access easily to the information, is possible that i will migrate all the documentation folder from the experimental repository for here, but i am not sure of it, i need to think it better, for now i put here just the things that we are needing