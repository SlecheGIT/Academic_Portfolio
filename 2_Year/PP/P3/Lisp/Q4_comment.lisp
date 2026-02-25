(defun sum-list (lista)
  (if (null lista); Se a lista for vazia
      0 ; Retorna 0
      (+ (car lista) (sum-list (cdr lista))) ; Soma o primeiro elemento da lista
	)
) ; Chama recursivamente a função para o resto da lista

(defun lcomp (L1 L2)
  (let (
		(sum-l1 (sum-list L1))(sum-l2 (sum-list L2)) ; Soma de L1 e Soma de L2
		)
		
		(cond
		  ((< sum-l1 sum-l2) -1) ; Se soma de L1 é menor que L2, retorna -1
		  ((= sum-l1 sum-l2) 0) ; Se somas são iguais, retorna 0
		  (t 1) ; Se soma de L1 é maior que L2, retorna 1
		)  
	)
)


; Como usar:
; (lcomp '(1 2 3) '(4 5 6))  ; Retorna -1, pois 1+2+3 < 4+5+6
; (lcomp '(1 2 3) '(6 5 4))  ; Retorna 0, pois 1+2+3 = 6+5+4
; (lcomp '(10 20 30) '(5 5 5))  ; Retorna 1, pois 10+20+30 > 5+5+5