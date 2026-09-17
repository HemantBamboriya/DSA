# Write your MySQL query statement below
select Department,Employee,Salary
from(
    select d.name as Department,
    e.name as Employee,
    e.salary as salary,
    DENSE_RANK() over(
        partition by e.departmentId
        order by salary desc
    )as rn
    from employee as e
    join department as d
    on e.departmentId=d.id
)as t
where rn<=3;
