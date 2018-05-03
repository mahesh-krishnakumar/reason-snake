type t;

let create: list((int, int)) => t;

let move: (t, Direction.t) => t;

let body: (t) => list(Cell.t);