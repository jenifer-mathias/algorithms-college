[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/kgpTODK_)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=11065399)
# compdist-webservice-balanceamento

## Atividade de Laboratório

Crie uma infraestrutura no Amazon EC2 ou Azure para rodar um serviço web (webservice) com balanceamento de carga, em nuvem.
Você deve implementar um mecanismo de balanceamento de cargas utilizando o servidor web Ngnix; (1 servidor front-end balanceador de carga)
Os servidores Web backend rodarão diretamente o webservice escutando na porta 5000  (2 servidores)

Disponibilize, no seu servidor, um serviço de conversão de real para dólar e euro como um webservice RESTFul: o usuário informa o valor em real, seu serviço obtém (de alguma API externa) a taxa do dólar e do euro para venda e devolve o valor em dólares e euros correspondentes ao valor em real fornecido, com saída JSON.  

A função deve se chamar: convertemoeda

A URL deverá ser  `<http://nome_da_maquina.dominio/convertemoeda/<VALOR>`

E o resultado deverá ser em JSON:

```
{
   “conversao”: [
    “real”: <VALOR>,
    “dolar”: <VALOR_EM_DOLAR>,
    “euro”: <VALOR_EM_EURO>,
   ]
}
```

Você deve implementar seu webservice em Python com Flask (esta atividade deve ser feita desta forma; outras atividades poderão, eventualmente, ser em linguagem livre).

Exemplos/tutoriais:

- https://dzone.com/articles/restful-web-services-with-python-flask (bem simples, fácil de usar)
- https://opensource.com/article/17/3/writing-web-service-using-python-flask (mais complexo, mostra uma aplicação bem estruturada)
- https://programminghistorian.org/en/lessons/creating-apis-with-python-and-flask (bem completa, documentação detalhada)
- https://www.datascienceblog.net/post/programming/flask-api-development/ (mostra como documentar a API com Swagger, muito bom)
- https://realpython.com/flask-by-example-part-1-project-setup/ (quase um curso completo para uma aplicação bem completa e complexa)


O que entregar no GitHub: Todo o código, Um relatório em PDF com todos os prints da execução, captura de telas e detalhamento da implementação. 

No dia determinado pelo professor os grupos farão a apresentação/demonstração da execução do sistema em funcionamento.
