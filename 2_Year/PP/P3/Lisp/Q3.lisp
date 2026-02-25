(defun fib (n)
  (cond
	((= n 0) 0)       ; Caso base: Fibonacci de 0 é 0
    ((= n 1) 1)       ; Caso base: Fibonacci de 1 é 1
    (t (+ (fib (- n 1)) (fib (- n 2)))) ; Soma dos dois anteriores
  )
)

; Como usar:
; (fib 0)  ; Retorna 0
; (fib 1)  ; Retorna 1
; (fib 5)  ; Retorna 5
; (fib 10) ; Retorna 55
