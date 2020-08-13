(import-module "file")
(import-sys "file2")

(display 8)

(declare x 5) ; comment

(if (eq? x 5) (display "five") (display "not five"))

(+ 5 5 (* 3 7))

(* 8 5 2 (/ 7 3))

; (declare f (lambda (x y) (+ x y 1)))
(declare (f x y) (+ x y 1))
(f (+ 5.5 7))

(express z (f 8))
;
(express y (quote x))
(express pi (quote (3 1 4 1 5)))
; (express m (quote (1 2 3 4 5)))

(lambda (x) (+ x 1)) ; not working

; (declare f (lambda (x y) (+ x y))) ; not working either
; conflicting func names and something else?