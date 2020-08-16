; math.scm

; works: true
; (express my-favorite-num (+ 5 3))
; (display my-favorite-num)

; works: true
; (express x (+ 5 3 2 (* 2 3))) ; -> 16
; (display x)

; works: true
; numbers are now converted to floats properly in the c++ file


; (express m (* 8 2 (/ 5 3))) ; -> 80 / 3 -> it works!
; (display m)

; DOES NOT WORK
; (declare (f a b c) (* a b (/ 3 c)))
; (display (f 1 2 3))

(declare x (/ 5 2))
(display x)

; works: true
; (express j (/ 2)) ; -> 1
; (display j); - this works now. Yay!

; (display x)
; (display m)
; (display j)