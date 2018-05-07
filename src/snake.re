type t = list(Cell.t);

let gainWeight = tail => {
  let oldTail = tail |> List.rev;
  let oldTailEnd = oldTail |> List.hd;
  let newTailEnd =
    Cell.create((Cell.x(oldTailEnd) + 1, Cell.y(oldTailEnd)));
  [newTailEnd];
};

let move = (snake, direction, food) => {
  let head = List.hd(snake);
  let newTail = snake |> List.rev |> List.tl |> List.rev;
  let foodCell = Food.position(food);
  let newTailEnd = head == foodCell ? gainWeight(newTail) : [];
  let newHead =
    switch (direction) {
    | Direction.Down => Cell.create((Cell.x(head), Cell.y(head) + 1))
    | Direction.Right => Cell.create((Cell.x(head) + 1, Cell.y(head)))
    | Direction.Left => Cell.create((Cell.x(head) - 1, Cell.y(head)))
    | Direction.Up => Cell.create((Cell.x(head), Cell.y(head) - 1))
    };
  [newHead] @ newTail @ newTailEnd;
};

let create = xs => List.map(Cell.create, xs);

let body = t => t;