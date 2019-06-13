Para começar implementei os testes pedidos:
O teste quatro: sempre dá falha de segmentação
O teste cinco :que da falha de divisão por zero
O teste seis :que entra em loop infinito
Teste sete :que é um loop demorado ->  onde para fazer mesmo fiz um for ->  indo ao número bem grande
O teste oito: que ele tem assert que falha e acertam ->  que no caso, podemos perceber que Se um falhar, O teste inteiro falha
O teste nove só faz vários prints 0 a 100
O teste 10 E 11 variam só pelo sleep



Após a criação dos testes, implementei No runner.h
A função sigHandler -> que está encarregada em receber o sinal de cntrol-c e trata-la
Depois disso fiz um for para fazer os filhos
Cada filho roda um teste separado
Em caso de sucesso retorna 0 e caso contrario -1
Logo apos,  faço outra for  onde esperarei processos filhos
Salva variável do processo filho no status
Mostra o retorno  em caso tenha sucesso  adiciona  em uma variável pass_count +1
Em casa tem problema->retorna fail e motivo do problema