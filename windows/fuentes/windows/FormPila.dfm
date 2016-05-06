object frmPila: TfrmPila
  Left = 695
  Top = 77
  Width = 170
  Height = 300
  HorzScrollBar.Visible = False
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSizeToolWin
  Caption = 'Ens2001-Pila'
  Color = clBtnFace
  Constraints.MaxWidth = 170
  Constraints.MinHeight = 300
  Constraints.MinWidth = 170
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = Cerrar
  OnDeactivate = PilaDeactivate
  OnHide = Ocultar
  OnKeyDown = LeerTecla
  OnPaint = Actualizar
  OnResize = MemoriaResize
  OnShow = Mostrar
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 47
    Top = 3
    Width = 45
    Height = 13
    Caption = 'Dirección'
  end
  object Label3: TLabel
    Left = 102
    Top = 3
    Width = 24
    Height = 13
    Caption = 'Valor'
  end
  object grdPila: TStringGrid
    Left = 7
    Top = 16
    Width = 143
    Height = 190
    ColCount = 3
    DefaultColWidth = 40
    DefaultRowHeight = 16
    FixedCols = 0
    RowCount = 65536
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
    ScrollBars = ssVertical
    TabOrder = 0
    OnDblClick = EditarMemoria
    OnKeyDown = LeerTecla
    OnTopLeftChanged = Actualizar
  end
  object btnCentrar: TButton
    Left = 8
    Top = 216
    Width = 145
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Caption = 'Ir a Puntero de Pila'
    TabOrder = 1
    OnClick = BotonCentrarClick
    OnKeyDown = LeerTecla
  end
  object txtIrA: TEdit
    Left = 8
    Top = 248
    Width = 65
    Height = 21
    Anchors = [akLeft, akRight, akBottom]
    TabOrder = 2
    OnKeyDown = LeerTecla
  end
  object btnIrA: TButton
    Left = 80
    Top = 248
    Width = 73
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Caption = 'Ir a Dirección'
    Default = True
    TabOrder = 3
    OnClick = BotonIrAClick
    OnKeyDown = LeerTecla
  end
end
