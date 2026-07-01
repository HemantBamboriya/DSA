# Write your MySQL query statement below
select w.name,w.population,w.area
from World as w
where w.population>=25000000 || w.area>=3000000;