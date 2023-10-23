#lang racket
#|  About
    Assignment 1 for CPSC 3740
    - learning how to use/code racket
|#

#| question 1
    
    write a function which looks in arra y to see if object x is present in that array
    if it is returns #t (true) or returns #f(false) if it's not

    things used
    - define used to define function
    - cond 
        - rackets form of a switch statement
        - runs through differnt conditions define in it's body
    - null? 
        - check  if list y is empty
    - equal? 
        - checks if object x is equal to object y
    - list? 
        - checks if objects a list
    - else
        - handles any codition not covers
    - car
        - Returns the first element of a pair (this case y).
|# 
(define (mymember? x y)
    (cond
        ;check if y is empty list, sense that wouild make x not be presnt 
        ;return #f(flase)
        ((null? y)
            #f
        )
        ;check if x is eqaul (using equal?) to y if so return 
        ;#t  (ture) otherwise move on
        ((equal? x (car y)) 
            #t
        )      
        ;check rest of the list
       (else(mymember? x (cdr y))
       )
    )
)

(write "Assignment 1")
(newline)
(newline)

#|Testing question 1
    - display 
        - acts as rackets Cout
|#
;testing if #t ture case works
(write "Question 1")
(newline)
(display (mymember? '(4 5(6)) '(1 2 3(4 5 (6)))))
(newline)
(display (mymember? 1 '(1 2 3(4 5 (6)))))

;testing if #f false case works
(newline)
(display (mymember? 4 '(1 2 3(4 5 (6)))))

#| question 2
   write a function to add an object at the end of a list
|#
(define (myappend x y)
  ; adding y onto the end of list x
   (append x (list y))    
)

#|Testing question 2
|#
(newline)
(newline)
(write "Question 2")
(newline)
(display (myappend '(1 2 3) 4))
(newline)
(display (myappend '(1 2 3) '(4 5 6)))
(newline)
(display (myappend '() '(4 5 6)))

#|Question 3
  write a function that takes two lists x and y and then returns a list
  that has the elments of x followed by elements of y
  that are not found in x
|#
(define (myunion x y)
    (cond
      ; if list y is empty return final union
      ; of list
        ((null? y) 
            x
        )
        ; check if current charcater of y is in list x
        ; if not add it to end of list x
        ((not (mymember? (car y) x))
            (myunion (myappend x (car y)) (cdr y))
        )
        ;otherwise contunie through list y until end
        (else
         (myunion x (cdr y))
        )
    )
)
#|Testing Question 3
|#
(newline)
(newline)
(write "Question 3")
(newline)
(display (myunion '(1 3 5 7 0) '(1 2 3 4 5 6 7 )))