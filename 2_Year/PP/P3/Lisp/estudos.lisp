(defun enesimo(L n)
    (cond
        ((= n 0) (car L))
        ((/= n 0) (enesimo (cdr L) (- n 1)))
        ((null L) '())
    )
)

(defun insere_em_ordem (element lista)
    (cond
        ((null lista) (list element))
        ((<= element (car lista)) (cons element lista))
        ((> element (car lista)) (cons (car lista) (insere_em_ordem element (cdr lista))))
    )
)

(defun ordena (lista)
    (if (null lista)
        '()
        (insere_em_ordem (car lista) (ordena (cdr lista)))
    )
)


(defun inverte (l)
    (if (null l)
        '()
        (append (inverte (cdr l)) (list (car l)))
    )
)
;(load "C:/Users/Sleche/Desktop/PP/Lisp/estudos.lisp")