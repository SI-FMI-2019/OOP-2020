# Inheritance types and access modifiers

##### Who can access members in different classes

| Access          | public | protected | private |
| --------------- | ------ | --------- | ------- |
| Same class      | yes    | yes       | yes     |
| Derived classes | yes    | yes       | no      |
| Outside classes | yes    | no        | no      |

#### When using public inheritance

- **Public** members of the base class become **public** members of the derived class
- **Protected** members of the base class become **protected** members of the derived class
- **Private** members of the base class **are never accessible directly from the derived class**, but can be accessed through calls to the **public** and **protected** members of the base class.