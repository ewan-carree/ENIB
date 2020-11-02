select nom from restaurant where ville='Lorient';
select nb_etoiles from restaurant where nom='Tavarn ar roue Morvan';
select nom from restaurant where nb_couverts>20;
select nom from ingredient where pays='France';
select prix from plat where nom='Raclette';

select distinct r.pays from restaurant r inner join ingredient i on (r.pays=i.pays);

select nom from ingredient union select nom from plat;

select avg(nb_etoiles) from restaurant where ville='Lorient';
select count(id_restaurant) from restaurant where ville='Lorient';

select nom from restaurant where ville='Lorient' group by nb_etoiles order by nb_etoiles desc;

select nom from restaurant where ville = 'Lorient' and nb_couverts>=10 group by nb_couverts having count(*)>=1;
