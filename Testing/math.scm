; math.scm

(declare top-level 245); pass

(express my-favorite-num (+ 5 3)); pass
(express x (+ 5 3 2 (* 2 3))); pass
(express m (* 8 2 (/ 5 3))); pass

; DOES NOT WORK
; (declare (f a b c) (* a b (/ 3 c)))
; (display (f 1 2 3))

; auto y = div_d(3, 5.0, (double) x, (double)(mul_d(3, 2.0, 3.0, (double)(sub_d(2, 2.0, 1.0)))));
; (express y (/ 5 x (* 2 3 (- 2 1)))); fail

; (express y (/ 5 x)); works
; (express y (/ 5 x (* 2 2))); works
(express y (/ 5 x (* 2 3 (- 2 1)))) ; works



(express j (/ 2)); works differently under my transpiler and Chez Scheme

(display top-level)
(newline)
(display my-favorite-num)
(newline)
(display x)
(newline)
(display m)
(newline)
(display y)
(newline)
(display j)


; auto y = div_d(3, 5.0, (double) x, (double)(mul_d(3, 2.0, 3.0, (double)(sub_d(2, 2.0, 1.0)))));
; (express y (/     5             x          (*        2    3                   (- 2 1)))); now, it works