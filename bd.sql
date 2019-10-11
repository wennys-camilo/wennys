drop database Academia;

create database if not exists Academia
CHARACTER SET utf8mb4
COLLATE utf8mb4_unicode_ci;

use Academia;

create table if not exists financeiro(
  id_financeiro int not null unique auto_increment,
  primary key(id_financeiro)
)default charset = utf8;

create table if not exists plano(
id_plano int not null unique auto_increment,
valor decimal(10,2) not null,
vencimento date, /* ano-mes-dia */
id_financeiro int not null,
modalidade enum('Musculação','FitDance','Luta','Crossfit'),
primary key(id_plano),
constraint foreign key (id_financeiro) references financeiro(id_financeiro)
)default charset = utf8;


create table if not exists cliente(
  id_cliente varchar(50) not null unique, /* CPF */
  nome varchar(45) not null,
  sexo enum('M','F'),
  id_plano int not null,
  primary key(id_cliente),
  constraint foreign key (id_plano) references plano(id_plano)
)default charset = utf8;

create table if not exists pagamento_instrutor(
  id_pagamento int not null ,
  valor decimal(10,2) not null,
  horaTrabalhadas time,
  id_financeiro int not null,
  primary key(id_pagamento),
  constraint foreign key(id_financeiro) references financeiro(id_financeiro)
)default charset = utf8;

create table if not exists instrutor(
  id_instrutor int not null unique,
  nome varchar(45) not null,
  sexo enum('M','F') not null,
  horarioEntrada time,
  horarioSaida time,
  id_pagamento int not null,
  primary key(id_instrutor),
  constraint foreign key(id_pagamento) references pagamento_instrutor(id_pagamento)
)default charset = utf8;

create table if not exists catraca(
  id_catraca int not null auto_increment unique,
  horarioEntrada time,
  horarioSaida time,
  id_cliente varchar(50) not null,
  primary key(id_catraca),
  constraint foreign key(id_cliente) references cliente (id_cliente)
)default charset = utf8;

insert into financeiro values('1');

insert into plano values('1',150.00,'2019-11-12','1','FitDance');
select * from plano;

insert into cliente values('66325120','wennys','M','1');

select *from cliente;
