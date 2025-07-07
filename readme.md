# Mads Knudsen companion site
This Github.io is primarily meant as a companion site for my CV, illustrating some of the projects on there.

just frigging use that parent and children know eachother

## TODO:
- [ ] DPL
    - [ ] All dpl keywords in highlight
    - [ ] All dpl keywords in description
    - [ ] Add input csv feature
    - [ ] Add export csv feature
    - [X] Make console pretty
    - [ ] Refactor to oop
- [ ] Matrix Library
    - [X] Implement method changing
    - [ ] Implement calculation
        - [X] Add
        - [X] Subtract
        - [X] Dot product
        - [X] Determinant
        - [X] Ref
        - [X] Rref
        - [X] Qr
        - [X] Plu
        - [ ] Power
    - [X] Reset result on method change
    - [X] Implement clear
    - [X] Make results uneditable
    - [ ] Implement size changing
        - [X] Implement general size changing
        - [X] Implement individual size change
        - [ ] Make add and sub not use indiviual sizing
        - [ ] Make method modifer system to restrict matrix sizes
    - [ ] Add error console (some methods are very specific)
    - [X] Auto select matrix 
- [ ] Rule of Inference Builder 
    - [ ] Implement drag and drop
        - [ ] Drop for ordering 
        - [ ] Update rule hitbox
            - [ ] The highest premise takes precedence 
            - [ ] Update hitbox from inner rules
        - [ ] Fix text editing of higher rules
        - [ ] Fix insertion in higer rules
        - [ ] Fix size updating
        - [ ] implement dragging out rules again
    - [ ] Implement text system
        - [ ] Implement math charecters
        - [ ] Implement cursor
        - [ ] Implement ctrl + z and ctrl + y
        - [ ] Implement selection
    - [ ] Implement delete of rules
    - [ ] Implement zoom or font size change
    - [ ] implement output to latex

- [X] Fix file structure
### Bugs
- [X] Matrix sizes doesn't match when changeing methods 
- [X] Other methods doesn't work after Plu
- [X] Doesn't reset going from Rref to Qr
- [X] Calculation doesn't work
- [X] Vector calculations incorrect
- [ ] Footer not sticking to bottom if not fixed-bottom
- [ ] Bug where matrix breakes if no number in input
- [ ] Half bug: size of output is decided on the basis of the last min row and column
