object frmConsolaEjecucion: TfrmConsolaEjecucion
  Left = 276
  Top = 199
  Width = 473
  Height = 358
  Caption = 'Ens2001-Consola'
  Color = clBtnFace
  Constraints.MinHeight = 160
  Constraints.MinWidth = 200
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = Cerrar
  OnCloseQuery = ConfirmarCerrar
  OnHide = Ocultar
  OnResize = ConsolaResize
  OnShow = Mostrar
  PixelsPerInch = 96
  TextHeight = 13
  object lblTipo: TLabel
    Left = 9
    Top = 307
    Width = 3
    Height = 13
    Anchors = [akLeft, akBottom]
  end
  object mmoConsola: TMemo
    Left = 8
    Top = 8
    Width = 441
    Height = 289
    PopupMenu = PopupMenu1
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 0
    WantReturns = False
    WordWrap = False
    OnKeyDown = LeerTeclado
    OnKeyPress = LeerCaracteres
  end
  object ActionList1: TActionList
    Left = 361
    Top = 22
    object SeleccionarTodo: TAction
      Caption = 'SeleccionarTodo'
      OnExecute = SeleccionarTodoExecute
    end
    object Limpiar: TAction
      Caption = 'Limpiar'
      OnExecute = LimpiarExecute
    end
    object Copiar: TAction
      Caption = 'Copiar'
      OnExecute = CopiarExecute
    end
    object DeseleccionarTodo: TAction
      Caption = 'DeseleccionarTodo'
      OnExecute = DeseleccionarTodoExecute
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 402
    Top = 22
    object SeleccionarTodo1: TMenuItem
      Caption = 'Seleccionar Todo'
      ShortCut = 16449
      OnClick = SeleccionarTodo1Click
    end
    object Copiar1: TMenuItem
      Caption = 'Copiar'
      ShortCut = 16451
      OnClick = Copiar1Click
    end
    object DeseleccionarTodo1: TMenuItem
      Caption = 'Deseleccionar Todo'
      ShortCut = 16462
      OnClick = DeseleccionarTodo1Click
    end
    object Limpiar1: TMenuItem
      Caption = 'Limpiar'
      ShortCut = 16471
      OnClick = Limpiar1Click
    end
  end
end
