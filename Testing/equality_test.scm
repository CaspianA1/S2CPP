;equality_test.scm

(declare x 5)
(declare y 5)

(display (eq? x y)); should yield false
(newline)
(display (eqv? x y)); should yield true