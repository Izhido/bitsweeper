Public Class StartForm

    Private Sub LogoForm_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles Me.KeyPress

        If e.KeyChar = Chr(27) Then
            Close()
        End If

    End Sub

End Class