; math.scm

(define top-level 245)

(define my-favorite-num (+ 5 3))
(define x (+ 5 3 2 (* 2 3)))
(define m (* 8 2 (/ 5 3)))

; DOES NOT WORK
; (declare (f a b c) (* a b (/ 3 c)))
; (display (f 1 2 3))

; (define y (/ 5 x (* 2 3 (- 2 1))))
; (define y (/ 5 x))
(define y (/ 5 x (* 2 3 (- 2 1))))
(define j (/ 2)) ; -> 1

(define nn newline)


(display top-level)
(nn)
(display my-favorite-num)
(nn)
(display x)
(nn)
(display m)
(nn)
(display y)
(nn)
(display j)
