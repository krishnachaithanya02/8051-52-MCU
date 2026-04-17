ORG 0000H

MOV SP, #30H   

MOV A, #25H
MOV B, #47H

PUSH ACC       
PUSH B         

POP B          
POP ACC        

END