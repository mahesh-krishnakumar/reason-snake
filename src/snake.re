type t = list(Cell.t);

let move = (snake, direction) => {
  let head = List.hd(snake);
  let newTail = snake |> List.rev |> List.tl |> List.rev;
  let newHead =
    switch (direction) {
    | Direction.Down => Cell.create((Cell.x(head), Cell.y(head) + 1))
    | Direction.Right => Cell.create((Cell.x(head) + 1, Cell.y(head)))
    | Direction.Left => Cell.create((Cell.x(head) - 1, Cell.y(head)))
    | Direction.Up => Cell.create((Cell.x(head), Cell.y(head) - 1))
    };
  Js.log([newHead] @ List.rev(newTail));
  [newHead] @ newTail;
};

let create = xs => List.map(Cell.create, xs);

let body = t => t;