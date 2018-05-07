open Webapi.Dom;

let documentEventTarget =
  document
  |> Document.asHtmlDocument
  |> Ext.Option.andThen(HtmlDocument.body)
  |> Ext.Option.unsafelyUnwrapOption
  |> Element.asEventTarget;

let initialSnake = Snake.create([(13, 10), (12, 10), (11, 10), (10, 10)]);

let initialFood = Food.create((15, 9));

let initialDirection = Direction.Right;

let initialWorld = World.create(initialSnake, initialFood, initialDirection);

let state = ref(initialWorld);

let handleTick = () => {
  let oldWorld = state^;
  let newWorld = {
    ...oldWorld,
    snake: Snake.move(oldWorld.snake, oldWorld.direction, oldWorld.food),
    food:
      Food.position(oldWorld.food) == List.hd(Snake.body(oldWorld.snake)) ?
        Food.newFood() : oldWorld.food,
  };
  state := newWorld;
  Draw.clearScene();
  Draw.drawSnake(state^.snake);
  Draw.drawFood(state^.food);
};

Js.Global.setInterval(handleTick, 300);

let handleEvent = evt => {
  let oldWorld = state^;
  let parsedKey = evt |> Webapi.Dom.KeyboardEvent.key |> Key.parseKey;
  let newDirection = Key.getDirection(parsedKey, oldWorld.direction);
  let newWorld = World.create(oldWorld.snake, oldWorld.food, newDirection);
  state := newWorld;
};

Webapi.Dom.EventTarget.addKeyDownEventListener(
  handleEvent,
  documentEventTarget,
);