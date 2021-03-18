# #PARSING 
Exercise 1. Implement a library/program in a programming language of your
choosing to load and validate the following input file:
#
//comment l i n e s ( s k i p them )
#
Sigma :
word1
word2
. . .
End
#
//comment l i n e s ( s k i p them )
#
S t a t e s :
s t a t e 1
s t a t e 2
s t a t e 3 , F
. . .
s t a teK , S
. . .
End
#
// comment l i n e s ( s k i p them )
#
T r a n s i t i o n s :
s t a teX , wordY , s t a t e Z
s t a teX , wordY , s t a t e Z
. . .
End
Sections can be in any order. By validation we ask to check that transition
section has valid states (first and third word) and valid words (word two). Note
that states can be succeeded by ”F”, ”S”, both or nothing. ”S” symbol can
succeed only one state.