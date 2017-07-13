open Glamor;

let component = ReasonReact.statelessComponent "TypeDetails";

let tableCls =
  css [
    borderSpacing "0 5px",
    display "table",
    margin "0 auto",
    marginTop "5px",
    width "auto"
  ];

let rowCls = css [display "table-row"];

let cellStyle = [display "table-cell", padding "10px", width "200px"];

let borderCellStyle = "solid 1px black";

let keyCellCls =
  css @@
  CssUtils.mixStyles
    cellStyle
    [
      backgroundColor "#337ab7",
      border borderCellStyle,
      borderRadius "30px 0 0 30px",
      borderRight "none",
      color "#fff",
      fontWeight "bold",
      minWidth "150px",
      textAlign "center",
      verticalAlign "middle"
    ];

let valueCellCls =
  css @@
  CssUtils.mixStyles
    cellStyle
    [
      border borderCellStyle,
      borderRadius "0 30px 30px 0",
      borderLeft "none",
      fontWeight "bold",
      wordBreak "break-word",
      width "auto"
    ];

let titleCls = css [fontSize "20px", padding "15px", textAlign "center"];

let typeDetailsCls =
  css [
    border "solid 1px #337ab7",
    borderRadius "36px",
    fontSize "12px",
    height "50%",
    margin "15px",
    maxHeight "50%",
    padding "0 15px",
    width "auto"
  ];

let scrollableAreaCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin
    [maxHeight "100%", minHeight "0", overflow "auto", width "auto"];

let showRootInformation data =>
  Js_undefined.testAny data ?
    ReasonReact.nullElement :
    <div className=rowCls>
      <span className=keyCellCls> (ReasonReact.stringToElement "Root ") </span>
      <span className=valueCellCls> (ReasonReact.stringToElement data) </span>
    </div>;

let make ::description ::icon ::root ::virtualType _children => {
  ...component,
  render: fun _ =>
    <div className=typeDetailsCls>
      <div className=titleCls>
        (ReasonReact.stringToElement "Additional type information")
      </div>
      <div className=scrollableAreaCls>
        <div className=tableCls>
          (showRootInformation root)
          <div className=rowCls>
            <span className=keyCellCls>
              (ReasonReact.stringToElement "Description ")
            </span>
            <span className=valueCellCls>
              (ReasonReact.stringToElement description)
            </span>
          </div>
          <div className=rowCls>
            <span className=keyCellCls>
              (ReasonReact.stringToElement "Icon ")
            </span>
            <span className=valueCellCls>
              (ReasonReact.stringToElement icon)
            </span>
          </div>
          <div className=rowCls>
            <span className=keyCellCls>
              (ReasonReact.stringToElement "Virtual ")
            </span>
            <span className=valueCellCls>
              (ReasonReact.stringToElement @@ string_of_bool virtualType)
            </span>
          </div>
        </div>
      </div>
    </div>
};
