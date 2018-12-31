let component = ReasonReact.reducerComponent("Board");

let getStreaks = cells => {
  open Array;
  let numRows = length(cells);
  let numColumns = length(cells[0]);
  let columns =
    make(numColumns, ())
    |> mapi((columnIndex, _) =>
         make(numRows, ())
         |> mapi((rowIndex, _) => cells[rowIndex][columnIndex])
       );

  let diagonals = [|
    make(numColumns, ()) |> mapi((index, _) => cells[index][index]),
    make(numColumns, ())
    |> mapi((index, _) => cells[index][numColumns - index - 1]),
  |];

  columns |> append(diagonals) |> append(cells);
};

let make = (~size, _children) => {
  ...component,
  initialState: () => {},
  reducer: (action, state) => ReasonReact.Update(),
  render: self => <div /* state -> [Cell] */ />,
};
