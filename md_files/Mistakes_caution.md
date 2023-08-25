1. Always be cautious of '1 and 2' in Number theory Ques.
 ////
2. Always treat your edge cases distinctly, never try to indulge them in usual loops! ////

3. Always check back and forth for equality cases!

4. always add a break after f++; // helps optimise leftover complexity!

5. always sort before using upper_bound! //now kinda fixed

6. any changing DS is best declared as global and cleared after each test case!
  // #pass by ref
7. #Brute_Force_Caution: whenever there's a limit on a[i], just go ahead with brute force! // #O(a[i]*n)

8. whenever you're stuck on a question with greedy approach, try shifting to : Binary_search, 2 pointers, elegant brute force or graphs/trees!
// tradeoff bw approches
9. Beware to use Multisets instead of sets when required and use to delete from multisets, always use address and not *it !
//got it
10. beware to declare stacks/queues/ms in fo(i,n) if using only in cols in matrix questions.
 // beware what you declare and where you declare
11. always be more cautious with base cases etc whenver the matrix is nxm!
#Never Forget m!!!!!!!!!!!!
  // always cross check the input/output data in case samples fail or you get an RE
12. You can't use maps etc or any logn operation inside already O(n*root(n)).
// ump with custom hash
13. use round(pow(a,b)) for integer calculations // ompi
14. typecast (int)v.size() #always // gotcha
15. always beware of precedence in cpp! // vs code intellisense op
16. if(mp.find(i) != mp.end()) instead of if(mp[i]) can save a lot from MLEs! // gg
17. set.lower_bound is O(logn) while lower_bound(all(set)) is O(n) // gotcha
18. s+='a' instead of s=s+'a' // gotcha
19. always take the whole input before checking upon any base cases! //gotcha
20. if you wanna find always use ms.find for a multiset! //gotcha
21. ms.count is linear in number of occurences! //gotcha
22. prefer sqrtl instead of sqrt. //gotcha
23. __builtin_popcountll to find number of set bits. 
24. In C++, comparator should return false if its arguments are equal. //?????
25. ll x=1<<40 would not give 2^40, so instead use 1LL<<40!! //ompi
26. always go for ranges, while writing predicate funcitons instead of going for exact values!!!  // yup

27. Don't overthink, at first just try to go for the simplemost approach, use Implementations.md for reference!//oki sir

28. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
29. if(!mp[x]) may cause tle if the map is iterated later on! //got it

30. Even maps can give TLE some times so try using hash arrays instead of them!
//oki
31. using pairs as a key in maps can give you unwanted TLEs so its best to avoid them(log2(2*2^64))!!!!
//oki

32. beware of substr function!!! //oki length!
33. learn when to change alter your point of view, just ask yourself, my logic may be accurate but is it implementable/optimal??? 
34. You can also use size in DSU(Might be a lot of help in some cases!!)
35. Try your best to define the most extreme constraint Arrays!
36. While replacing maps with some hash array beware to take care of negative indices!!
37. never insert in a DS when you're fat looping over it
38. bitset<1000> bs1,bs2;  now bs1&bs2 will have complexity of O(1000/64);
