ORG 0000H

MAIN:
    ACALL DELAY    
    SJMP MAIN      

DELAY:
    MOV R2, #255 

D1: MOV R1, #255   
D2: MOV R0, #255   

D3: DJNZ R0, D3    
    DJNZ R1, D2    
    DJNZ R2, D1    

    RET            

END