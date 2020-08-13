; conditional.scm

(declare x 5)

(cond
   ((> x 5) (display "bigger"))
   ((< x 5) (display "smaller"))
   (display "equal"))