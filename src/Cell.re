/* a basic cell in a Tic Tac Toe game board */
let component = ReasonReact.statelessComponent("Cell");

let make = (~mark, ~onClick, ~color, _children) => {
  ...component,
  render: _self =>
    <span
      onClick
      style=(
        ReactDOMRe.Style.make(
          ~border="1px",
          ~borderColor="black",
          ~padding="20px",
          ~backgroundColor=color,
          (),
        )
      )>
      (ReasonReact.string(mark))
    </span>,
};
