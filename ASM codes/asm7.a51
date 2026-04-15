ORG 0000H

START:
    MOV P1, #0FFH     ; Initially all LEDs OFF (active LOW)

MAIN_LOOP:
    MOV P1, #00H      ;
    ACALL DELAY

    MOV P1, #0FFH     
    ACALL DELAY

    SJMP MAIN_LOOP    


DELAY:
    MOV R2, #255
D1: MOV R1, #255
D2: MOV R0, #255
D3: DJNZ R0, D3
    DJNZ R1, D2
	
    MOV R2, #255   
D4: DJNZ R2, D4
    RET

END