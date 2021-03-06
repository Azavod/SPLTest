section .text
global checker
; returns 1 in rax if true
; returns 0 in rax if false
; Нарисуйте и закодируйте на ассемблере конечный автомат, который проверяет входную строчку и отвеча-
; ет, содержит ли она ровно два слова, а за ними число. Слова состоят только из символов [a-z], разделены
; только одинарными пробелами. Макрос get_symbol кладёт в ah следующий символ.
checker:
    xor rcx, rcx        ; счётчик слов
    .loop:
        get_symbol      ; макрос, кладёт в ah следующий символ
        cmp ah, 0x20    ; пробел?
        je .space
        cmp ah, 57      ; цифра?
        jg .loop
        test ah, ah
        jz .false       ; дошли до конца строки, не встретив цифру
        .number:
            cmp rcx, 2
            jne .false
            get_symbol
            test ah, ah ; проверяем, закончилась строка или нет
            jnz .false
        .true:
            mov rax, 1
            ret
        .space:
            inc rcx     ; наращиваем счётчик слов
            jmp .loop
        .false:
            xor rax, rax 
            ret
