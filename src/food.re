type t = Cell.t;

let create = Cell.create;

let position = food => food;

let newFood = () => create((Random.int(10) + 1, Random.int(10) + 1));