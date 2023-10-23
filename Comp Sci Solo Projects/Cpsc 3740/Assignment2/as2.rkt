#lang racket
#|  Assignment 2 for CPSC 3740
|#

#|  Question 1
    The size of a tree is defined by the number of nodes in a tree. For example,
    the example tree above has a size of 6.
    Write a function tree-size that will take a tree representation as described and return
    the size of the tree.
|#

(define(tree-size tree)
  (cond
        ((null? tree) 0) ; element is empty, which has a size of 0
        ; node is root/not connected to other parts so return size 1
        ((not (list? (car tree)))
            (+ 1 (tree-size (cdr tree)))
        )
        (else
            (+ (tree-size (car tree))
             (tree-size (cdr tree)))
        )
    )
)

;testing question 1
(tree-size '(1 (2 (3 () ()) (4 () ())) (15 () ()) (16 () ()))) ; outputs 6
(tree-size '(1 (2 (3 3 (2 2) ()) (4 () ())) (15 () ()) (16 () ()))) ; outputs 9
(tree-size '(1 1)) ; outputs 2

#|  Question 2
    The level of a node in the tree is the number of nodes in the path from
    the root to the node (including itself). For example, the node 15 in the example tree
    above has a level of 2.
    Write a function prune-tree that will take a tree representation as well as an integer
    level. It will return a new tree containing only nodes that have level not exceeding
    level.
    The order of the nodes in the result list should be the same as the original order in the
    tree. You may assume that level is a non-negative integer
|#

(define (prune-tree tree level)
  (cond
    ; element is empty, return empty list
    ((null? tree) '()) 
    ; check if level has reach 0, if it has then the maximum number of 
    ; levels has been reach, and return empty list from here on
    ((= level 0) '()) 
    ;checking if node is a subtree, and then run through that
    ((list? (car tree))
     (cons 
        (prune-tree (car tree) (- level 1))
        (prune-tree (cdr tree) level)
        )
    )
    ;node is not sub tree
    (else
     (cons 
        (car tree)
        (prune-tree (cdr tree) level)
        )
    )
    )
)

; testing question 2
(prune-tree '(1 (() (3 () ()) (4 () ())) (15 () ()) (16 () ()) 2) 2)

(prune-tree '(1 1) 2) 

#|  Question 3
    
    Write a function called count-tree that will take a tree representation and
    an integer target, and determine how many times the element target is located in
    the tree.
|#

(define (count-tree tree target)
    (cond
        ((null? tree) 0) 
        ((equal? target (car tree)) 
            (+ 1 (count-tree (cdr tree) target))
        ) 
        ((list? (car tree))
            (+ (count-tree (car tree) target) 
               (count-tree (cdr tree) target)
            )
        )
        (else
            (count-tree (cdr tree) target)            
        )
    )
)

; testing question 3
(count-tree '(1 1 2) 1) ; outputs 2

(count-tree '(1 (2 (3 (2) (2)) (4 () (2))) (15 () ()) (16 () ())) 2)  ; out put 4
