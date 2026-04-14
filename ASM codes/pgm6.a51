ORG 0000H
START:
	MOV P1, #00H
TOGGLE:   
     CPL P1.2
     ACALL DELAY
	 SJMP TOGGLE
	 
	DELAY:      MOV R2, #60      ; Outer loop count (3 × 20 from 1-sec version)
DELAY1:     MOV R3, #0FFH    ; Middle loop count
DELAY2:     MOV R4, #0FFH    ; Inner loop count
DELAY3:     DJNZ R4, DELAY3  ; Decrement R4 until zero
            DJNZ R3, DELAY2  ; Decrement R3 until zero
            DJNZ R2, DELAY1  ; Decrement R2 until zero
            RET

            END	 