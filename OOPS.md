1. method overridden-> calls method of the closest ancestor(if public), if not public it throws error
2. private -> not accessible by children
3. Parent's pointer can refer to child's objects , but the other way around isn't possible
4. object slicing happens when a derived class object is assigned to a base class object.
5. parent's pointer can point to child's objects but still can only call its virtual functions
6. if a child overrides a particular name, then all the functions of the same name in the parent become hidden even though they may have had different parameters as input
It can be called if you use obj.ParentClassName::fun(overloaded)
7. can't use initialiser list on parent's variables