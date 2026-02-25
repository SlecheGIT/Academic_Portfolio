

(defun fib (n)
    (cond
    ((= n 0) 0)
    ((= n 1) 1)
    ((> n 1) (+ (fib (- n 1)) (fib (- n 2)) ))
    )
)

(defun fat (n)
    (if (= n 0)
        1
        (* (fat (- n 1)) n)
    )
)

(defun sumation (L)
    (if (not (null L))
        (+ (pop L) (sumation L))
        0
    )
)

(defun lcomp (L1 L2)
    (let ((X (sumation L1)) (Y (sumation L2)))
        (cond
            ((< X Y) -1)
            ((= X Y) 0)
            ((> X Y) 1)
        )
    )
)