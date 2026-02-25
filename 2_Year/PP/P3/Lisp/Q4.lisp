(defun sommation_list (L)
    ( if (not (null l))
        (+ (pop L) (sommation_list L))
        0
    )
)

(defun lcomp (L1 L2)
    (let ((list1 (sommation_list L1)) (list2 (sommation_list L2)))
        (cond
            ((< list1 list2) L1)
            ((= list1 list2) 0)
            ((> list1 list2) -1)
        )
    )
)

; uso : (lcomp '(45)) ou (lcomp (list (4 5 6)))