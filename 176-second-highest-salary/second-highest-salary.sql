# Write your MySQL query statement below
select (
select salary 
from(
    select salary,
    dense_rank() over(
        order by salary desc
    )as rnk
    from employee
)as t

where rnk=2
limit 1
)as SecondHighestSalary;
