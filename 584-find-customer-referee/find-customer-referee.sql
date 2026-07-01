# Write your MySQL query statement below
select c.name
from Customer as c
where c.referee_id != 2 || c.referee_id is NULL;
